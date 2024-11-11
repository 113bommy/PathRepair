from collections import Counter
def solve(a,x):
    count = Counter(a)
    prev = 0
    for n in range(1,200):
        if n not in count:
            x-=1
        if x==-1: 
            prev=n-1
            break
    return prev



def main():
    t = int(input())
    ans = []
    for _ in range(t):
        n,x = [int(x) for x in input().split()]
        a = [int(x) for x in input().split()]
        ans.append(solve(a,x))
    
    for res in ans:
        print(res)
main()