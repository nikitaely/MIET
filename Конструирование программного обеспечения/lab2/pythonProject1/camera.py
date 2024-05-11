import tensorflow as tf
from tensorflow.keras.applications.resnet50 import ResNet50, preprocess_input
from tensorflow.keras.preprocessing import image
import numpy as np



# Загружаем предобученную модель ResNet50
model = ResNet50(weights='imagenet')
class Camera:
    def __init__(self, image_path):
        self.image_path = image_path

    def detect_car(self):
        img = image.load_img(self.image_path, target_size=(224, 224))
        img_array = image.img_to_array(img)
        img_array = np.expand_dims(img_array, axis=0)
        img_array = preprocess_input(img_array)

        predictions = model.predict(img_array)
        decoded_predictions = tf.keras.applications.imagenet_utils.decode_predictions(predictions, top=5)

        for predict in decoded_predictions:
            for imagenet_id, label, score in predict:
                if 'car' in label:
                    return True

        return False
