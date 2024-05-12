class DistanceSensor:
    def __init__(self, rsensor_3: bool = False, rsensor_4: bool = False, rsensor_5: bool = False, lsensor_3: bool = False) -> None:
        self.distance = None
        self.rsensor_3 = rsensor_3
        self.rsensor_4 = rsensor_4
        self.rsensor_5 = rsensor_5
        self.lsensor_3 = lsensor_3

    def get_distance(self):
        if self.rsensor_5 and not (self.rsensor_4 or self.rsensor_3 or self.lsensor_3):
            self.distance = 5
        if (self.rsensor_5 and self.rsensor_4) and not (self.rsensor_3 or self.lsensor_3):
            self.distance = 4
        if (self.rsensor_3 and self.rsensor_4 and self.rsensor_5) and not self.lsensor_3:
            self.distance = 3
        if not (self.rsensor_5 or self.rsensor_4 or self.rsensor_3 or self.lsensor_3):
            self.distance = -3
        else:
            self.distance = 0
        return self.distance