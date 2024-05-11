class WarningMeans:
    def __init__(self, distance: int, distance_for_activate: int, state: bool = False):
        self.distance = distance
        self.distance_for_activate = distance_for_activate
        self.state = state

    def activate(self):
        if self.distance < 0:
            self.state = False
        if self.distance <= self.distance_for_activate:
            self.state = True

    def print_state(self):
        pass

class TrafficLight(WarningMeans):
    def print_state(self):
        if self.state:
            print("Светофор включен")
        else:
            print("Светофор выключен")

class Dynamic(WarningMeans):
    def print_state(self):
        if self.state:
            print("Динамики включены")
        else:
            print("Динамики выключены")


class Barrier(WarningMeans):
    def print_state(self):
        if self.state:
            print("Шлагбаум опущен")
        else:
            print("Шлагбаум поднят")