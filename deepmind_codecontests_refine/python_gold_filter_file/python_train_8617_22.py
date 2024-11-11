from bisect import bisect_left,bisect_right

TO_ACII = 97

N = int(input())
S = ["0"] + list(input())
Q = int(input())

ABC = [[]for i in range(0,26,1)]#該当文字a:0 b:1 ...z:26 が何文字目に出てきたかを保持する配列

for i in range(1,N+1,1):
    ABC[ord(S[i])-TO_ACII].append(i)

ans = []
for i in range(0,Q,1):
    q = list(input().split())
    if q[0]=="1":#文字変更
        changed = S[int(q[1])]
        ABC[ord(changed)-TO_ACII].pop(bisect_left(ABC[ord(changed)-TO_ACII],int(q[1])))
        ABC[ord(q[2])-TO_ACII].insert(bisect_left(ABC[ord(q[2])-TO_ACII],int(q[1])),int(q[1]))
        S[int(q[1])]=q[2]
    else:
        tmpans = 0
        for i in range(0,26,1):

            if bisect_right(ABC[i],int(q[1])-1)<len(ABC[i]) and int(q[2]) >= ABC[i][bisect_right(ABC[i],int(q[1])-1)]:
                tmpans+=1
        ans.append(tmpans)

for i in range(0,len(ans),1):
    print(ans[i])
