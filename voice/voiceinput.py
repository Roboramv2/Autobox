from record import record
import librosa
import numpy as np
import requests

def filt(l):
    c = [0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1]
    for j in c:
        l.pop(j)
    l.pop(2)
    l.pop(2)
    l.pop(-1)
    return l

arr = record()
arr = arr.astype(np.float32)
mfcc = librosa.feature.mfcc(y=arr, sr=8000)
fv = []
for x in (mfcc):
    s = int(sum(x)/len(x))
    fv.append(s)
fv = filt(fv)

url = "https://fv-transport.herokuapp.com/fv"
print(fv)
requests.post(url,json={'fv':fv})
