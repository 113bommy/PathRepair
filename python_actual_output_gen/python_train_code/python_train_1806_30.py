def solution(n):
    need=n-10
    if need<0:
        return 0
    else:
        a = []
        i=2
        while i<=9:
            a.append(i)
            a.append(i)
            a.append(i)
            a.append(i)
            i+=1
        while i==10:
            j=1
            while j<=15:
                a.append(10)
                j+=1
            i+=1
        while i==11:
            j=1
            while j<=4:
                a.append(11)
                j+=1
            i+=1
        ans=0
        while need in a:
            ans+=1
            a.remove(need)
        return ans
    
def answer():
    n=int(input())
    print(solution(n))
answer()
