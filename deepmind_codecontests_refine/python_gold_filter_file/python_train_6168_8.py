# cook your dish here
import math

def main():
    for q in range(int(input())):
        N,K = map(int,input().split())
        st = input()
        dp = [0]*26
        for i in range(len(st)):
            dp[ord(st[i]) - ord('a')] += 1
        emp = -1
        for i in range(26):
            if dp[i]!=0:
                emp = i
                break
        if dp[emp]<K:
            ans = ""
            for i in range(26):
                K -= dp[i]
                if K<=0:
                    ans = chr(i+97)
                    break
            print(ans)
        else:
            ans = ""
            noe = 0
            for i in range(26):
                if dp[i] != 0:
                    noe += 1
            if noe==1:
                for i in range(dp[emp]//K):
                    ans += chr(emp+97)
                if dp[emp]%K !=0:
                    ans += chr(emp+97)
            elif noe==2:
                for i in range(dp[emp]-K+1):
                    ans += chr(97+emp)
                nex = -1
                for i in range(emp+1,26):
                    if dp[i]!=0:
                        nex = i
                if K<dp[emp]:
                    for j in range(dp[nex]):
                        ans += chr(97+nex)
                else:
                    for i in range(dp[nex]//K):
                        ans += chr(97+nex)
                    if dp[nex]%K!=0:
                        ans += chr(97+nex)
            else:
                for i in range(dp[emp]-K+1):
                    ans += chr(97+emp)
                for i in range(emp+1,26):
                    for j in range(dp[i]):
                        ans += chr(97+i)
            print(ans)
                
                
        
    
if __name__ == "__main__":
    main()
