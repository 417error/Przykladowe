Takie wpisy w MQTT Broker zanim zacznie się korzystać z MQTT...

====================
Topic:
homeassistant/sensor/sensorBedroomT/config

Payload:
{
   "device_class":"temperature",
   "state_topic":"homeassistant/sensor/sensorBedroom/state",
   "unit_of_measurement":"°C",
   "value_template":"{{ value_json.temperature}}",
   "unique_id":"temp01ae",
   "device":{
      "identifiers":[
          "bedroom01ae"
      ],
      "name":"Bedroom",
      "manufacturer": "Example sensors Ltd.",
      "model": "Example Sensor",
      "model_id": "K9",
      "serial_number": "12AE3010545",
      "hw_version": "1.01a",
      "sw_version": "2024.1.0",
      "configuration_url": "https://example.com/sensor_portal/config"
   }
}
===================
Topic:
homeassistant/sensor/sensorBedroomH/config

Payload:
{
   "device_class":"humidity",
   "state_topic":"homeassistant/sensor/sensorBedroom/state",
   "unit_of_measurement":"%",
   "value_template":"{{ value_json.humidity}}",
   "unique_id":"hum01ae",
   "device":{
      "identifiers":[
         "bedroom01ae"
      ]
   }
}

============================


================= testy

homeassistant/sensor/sensorBedroom/state

{
   "temperature":23.20,
   "humidity":43.70
}


====================================
PM

homeassistant/sensor/sensorBedroomPM1/config

{
   "device_class":"pm1",
   "state_topic":"homeassistant/sensor/sensorBedroom/state",
   "unit_of_measurement":"ug/m3",
   "value_template":"{{ value_json.pm1}}",
   "unique_id":"pm101ae",
   "device":{
      "identifiers":[
         "bedroom01ae"
      ]
   }
}


==============================

homeassistant/sensor/sensorBedroomPM25/config

{
   "device_class":"pm25",
   "state_topic":"homeassistant/sensor/sensorBedroom/state",
   "unit_of_measurement":"ppm",
   "value_template":"{{ value_json.pm25}}",
   "unique_id":"pm2501ae",
   "device":{
      "identifiers":[
         "bedroom01ae"
      ]
   }
}

=================

homeassistant/sensor/sensorBedroomPM10/config

{
   "device_class":"pm10",
   "state_topic":"homeassistant/sensor/sensorBedroom/state",
   "unit_of_measurement":"ppm",
   "value_template":"{{ value_json.pm10}}",
   "unique_id":"pm1001ae",
   "device":{
      "identifiers":[
         "bedroom01ae"
      ]
   }
}

============================================

homeassistant/sensor/sensorBedroom/state

{
   "temperature":23.20,
   "humidity":43.70
}
