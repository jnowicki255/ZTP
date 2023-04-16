import length_conv as length
import weight_conv as weight

# Wczytanie wartości
value = float(input("Podaj wartość do konwersji: "))

# Konwersje długości
print(value, "metrów to:", length.meter_to_yard(value), "jardów.")
print(value, "stóp to:", length.feet_to_centimeter(value), "centymetrów.")
print(value, "cali to:", length.cal_to_centimeter(value), "centymetrów.")

# Konwersje wagi
weightConverter = weight.WeightConv()
print(value, "funtów to:", weightConverter.pound_to_kilogram(value), "kilogramów.")
print(value, "kamieni to:", weightConverter.stone_to_kilogram(value), "kilogramów.")
print(value, "uncji to:", weightConverter.ounce_to_gram(value), "gramów.")