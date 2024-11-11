def int_input():
    a = int(input())
    return a

def int_list_input():
    a = list(map(int,input().split()))
    return a

def solve():
    n,m = int_list_input()
    arr = int_list_input()
    d = {}
    ans = 0
    
    for i in arr:
        for j in d:
            if j < i:
                ans += 1
        d[i] = d.get(i,0)+1
    print(ans)
    

if __name__ == '__main__':
    
    for _ in range(int(input())):
        solve()
    
    #print("Case",str(n)+":",str(ans))