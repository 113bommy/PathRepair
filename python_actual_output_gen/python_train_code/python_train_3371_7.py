arr = list(input())
fl = True
if len(arr)&1:
    fl = True
out = ""
while len(arr):
    if fl:
        out = arr[-1] + out
        arr.pop(len(arr)-1)
    else:
        out = arr[0] + out
        arr.pop(0)
    fl = not fl
print(out)