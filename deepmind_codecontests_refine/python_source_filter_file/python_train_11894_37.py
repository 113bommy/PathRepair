def run():
    t = int(input())
    for k in range(t):
        n = int(input())
        ans = [n]
        if n < 4:
            print(-1)
            continue
        for i in range(n,0,-1):  
            if i % 2:
                ans.append(i)

        ans.append(4)
        ans.append(2)
        for i in range(6, n+1,2):
            ans.append(i)
        print(*ans)
        
if __name__ == "__main__":
    run()