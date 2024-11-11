if __name__ == "__main__":
    while True:
        n = int(input())
        if n ==0:break
        count = 0
        for i in range(n):
            for j in  range(i+1,n):
                sum = (i+j)*(i+j-1)/2
                if  sum> n:break
                if sum == n:count +=1

        print(count)