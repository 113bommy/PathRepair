n , k = map(int,input().split())
ar = list(map(int,input().split()))
x = k - 1
count = 0

for i in range(n):
    if i == 0 :
        if ar[x] == 1 :
            count +=1

    else:
        l = x - i
        r = x + i
        if l >= 0 and r < n-1 :
            if ar[l] == 1 and ar[r] == 1 :
                count+=2

        elif l >= 0 and r > n - 1:
            if ar[l] ==1 :
                count+=1

        elif l < 0 and r <= n - 1 :
            if ar[r] == 1 :
                count+=1

        elif l < 0 and r > n - 1 :
            break

print(count)