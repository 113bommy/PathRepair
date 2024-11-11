a, b, c = map(int, input().split())

li = list(map(int, input().split()))

countt = 0
jus_wast = 0

for i in li:
    if i <= b:
        jus_wast += i
        if jus_wast <= c:
            pass
        else:
            jus_wast -= c
            countt += 1

print(countt)
