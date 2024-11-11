t=int(input())
for _ in range(t):
    s=input()
    cnt0=s.count("0")
    cnt1=s.count("1")
    ans=abs(cnt0-cnt1)
    if ans%2==0:
        print("NET")
    else:
        print("DA")