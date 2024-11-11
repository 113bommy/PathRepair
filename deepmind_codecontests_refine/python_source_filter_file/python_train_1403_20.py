__author__ = 'myduomilia'

def sortInstrument(instrument):
        return instrument.time

class Instrument:
    def __init__(self, ind, tim):
        self.ind = ind
        self.time = tim

n, time = list(map(int, input().split()))
arr = list(map(int, input().split()))
ans = 0
t = 0
instruments = []
for i, val in enumerate(arr):
    instruments.append(Instrument(i, val))
instruments.sort(key=sortInstrument)
a = []
for val in instruments:
    if t + val.time < time:
        a.append(val.ind)
        ans += 1
        t += val.time
print(ans)
print(" ".join(str(val) for val in a))

