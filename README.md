# Particle Edge Impulse Ingestion Example

This repository shows how to use a Particle LTE enabled module to build a training dataset for use with Edge Impulse. 

This firmware should be combined with a custom webhook configured in the Particle console with the following settings. The webhook is pointed to the [Edge Impulse ingestion API](https://docs.edgeimpulse.com/reference/data-ingestion/ingestion-api). It will make an API request each time a datapoint is published to the `training-data` event via `Particle.publish`.

The JSON data that should be applied to the custom webhook for this example is below:
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