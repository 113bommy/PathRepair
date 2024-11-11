if __name__ == "__main__":
    while 1:
        x,y,z = list(map(int,input().strip().split()))
        if x ==0 and y ==0 and z ==0:break
        data = []
        for i in range(1,z):
            t1 = i + int(i *  x/100)
            for j in range(1,z-t1+1):
                t2 = j + int(j * (x/100))
                if t1 + t2 == z:data.append([i,j])
        ans = 0
        for k in data:
            temp = k[0] + int(k[0]* (y/100)) + k[1] + int(k[1]* y/100)
            if  temp > ans: ans = temp
        print(ans)