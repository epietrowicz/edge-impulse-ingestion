# Particle Edge Impulse Ingestion Example

This repository shows how to use a Particle LTE enabled module to build a training dataset for use with Edge Impulse. 

This firmware should be combined with a custom webhook configured in the Particle console with the following settings. The webhook is pointed to the [Edge Impulse ingestion API](https://docs.edgeimpulse.com/reference/data-ingestion/ingestion-api). It will make an API request each time a datapoint is published to the `training-data` event via `Particle.publish`.

The Edge Impulse endpoint for adding training data is: `http://ingestion.edgeimpulse.com/api/training/data`

![webhook-config](https://github.com/user-attachments/assets/372a4ce4-81c9-4e6d-b339-7eafaee49b56)

The JSON data for this example is below. This format is defined by Edge Impulse's [API specification](https://docs.edgeimpulse.com/reference/data-ingestion/ingestion-api#example-of-raw-requests).

![webhook-json-data](https://github.com/user-attachments/assets/22ab28bd-b34d-48bf-9d9f-66db5d09a69c)

```JSON
{
  "payload": {
    "device_name": "test-som",
    "device_type": "msom",
    "interval_ms": 15000,
    "sensors": [
      {
        "name": "temp",
        "units": "F"
      }
    ],
    "values": [
        {{{PARTICLE_EVENT_VALUE}}}
    ]
  },
  "protected": {
    "alg": "none",
    "ver": "v1"
  },
  "signature": "00"
}
```
The headers contain some additional information about the data as well as your [Edge Impulse API key](https://docs.edgeimpulse.com/reference/edge-impulse-api/edge-impulse-api#api-key).

![webhook-http-headers](https://github.com/user-attachments/assets/b4816471-c50d-40dd-aa0e-9796ec98810b)
