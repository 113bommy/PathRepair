def find(x):
    if(x%2==1):
        print("Alice")
    else:
        print("Bob")
n = int(input().strip())
la = [int(x) for x in input().strip().split()]
odd = 0
even = 0
i = 0
mx = 0
mv = 1000**3
while i < n:
    if(la[i]%2==1):
        odd=1
    else:
        even=1
    mx = max(mx, la[i])
    mv = min(mv, la[i])
    i+=1
if(odd == 0):
    rem = mv
    for i in range(0, n):
        for j in range(i+1, n):
            if(la[i] > la[j]):
                mod = la[i]%la[j]
                if(mod == 0):
                    continue
                if(mod < rem):
                    rem = mod
                if(la[i]%mod != 0 and la[i]%mod < rem):
                    rem = la[i]%mod
                if(la[j]%mod != 0 and la[j]%mod < rem):
                    rem = la[j]%mod
            elif(la[j] < la[i]):
                mod = la[j]%la[i]
                if(mod == 0):
                    continue
                if(mod < rem):
                    rem = mod
                if(la[i]%mod != 0 and la[i]%mod < rem):
                    rem = la[i]%mod
                if(la[j]%mod != 0 and la[j]%mod < rem):
                    rem = la[j]%mod
    mv = ((mx//rem) - n)
    find(mv)
else:
    find(mx-n)
