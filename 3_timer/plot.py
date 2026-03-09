import matplotlib.pyplot  as plt
import pandas as pd

data = pd.read_csv("bench.csv", sep = ";")

plt.plot(data["size"], data["reference"], label = "reference")
plt.plot(data["size"], data["hoisted"], label = "hoisted")
plt.plot(data["size"], data["register_blocked"], label = "register_blocked")
plt.plot(data["size"], data["tiled"], label = "tiled")
plt.title("Matrix multiplication")
plt.legend()
plt.savefig("bench.png")

