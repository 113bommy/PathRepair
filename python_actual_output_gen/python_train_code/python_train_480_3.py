n = int(input())

def determine(s):
    if s[-2:]=="po":
        return "FILIPINO"
    if s[-4:]=="desu" or s[-4:] == "maku":
        return "JAPANESE"
    if s[-2:]=="mnida":
        return "KOREAN"

for step in range(n):
    print(determine(input()))
    