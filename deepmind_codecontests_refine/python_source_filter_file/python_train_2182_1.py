if __name__ == "__main__":
    while True:
        n = int(input())
        if n ==0:break
        nline = [i for i in range(n)]
        count = 0
        for i in range(n):
            for j in  range(i,n):
                if sum(nline[i:j]) > n:break
                if sum(nline[i:j]) == n:count +=1

        print(count)