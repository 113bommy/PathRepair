holes = list(map(int, input().split()))
mx = -1
for i in range(14):
    if holes[i]>0:
        temp2 = holes[i]
        temp = list(holes)
        temp[i] = 0
        ext = temp2//14
        for i in range(14):
            temp[i]+=ext
        temp2 = temp2%14
        while(temp2>0):
            if i+1 == 14:
                i = 0
            else:
                i+=1
            temp[i]+=1
            temp2-=1
        #print(temp)
        sm = 0
        for i in temp:
            if i%2 == 0:
                sm+=i
        mx = max(mx,sm)
print(mx)

