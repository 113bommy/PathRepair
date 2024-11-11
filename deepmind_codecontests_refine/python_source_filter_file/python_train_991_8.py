n = int(input())
a = list(map(int, input().split()))
a.append(90)
#print (len(a))
a.insert(0, 0)
a.append(1000)
for i in range (1, len(a)):
    if (a[i] - a[i - 1] > 15):
        print (min(90, a[i - 1] + 15))
        exit