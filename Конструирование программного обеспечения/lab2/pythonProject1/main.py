from sensor import DistanceSensor
from camera import Camera
from warning_means import TrafficLight, Dynamic, Barrier

sensors = (True, True, True, True)

distance_sensor = DistanceSensor(*sensors)
camera = Camera(image_path='True_1.jpg')

traffic_ligt = TrafficLight(distance_sensor.get_distance(), 4)
dynamics = Dynamic(distance_sensor.get_distance(), 5)
barrier = Barrier(distance_sensor.get_distance(), 3)

traffic_ligt.activate()
traffic_ligt.print_state()

dynamics.activate()
dynamics.print_state()

barrier.activate()
barrier.print_state()

if camera.detect_car() and traffic_ligt.state:
    print('Сообщение о наличии машины на перезде отправлено машинисту приближающегося поезда')

print()


