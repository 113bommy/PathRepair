N,A,B,C=map(int,input().split())
S=['']*(N+1)
for a in range(N):
    S[a]=input()

ans='Yes'
L_ans=['']*(N+1)
i=0
while i<N:
    if S[i]=='AB':
        if A>B:
            B+=1
            A-=1
            L_ans[i]='B'
        elif A<B:
            A+=1
            B-=1
            L_ans[i]='A'
        elif A==B and S[i+1]=='BC':
            B+=1
            A-=1
            L_ans[i]='B'
        else:
            A+=1
            B-=1
            L_ans[i]='A'
    elif S[i]=='AC':
        if A>C:
            C+=1
            A-=1
            L_ans[i]='C'
        elif A<C:
            A+=1
            C-=1
            L_ans[i]='A'
        elif A==C and S[i+1]=='BC':
            C+=1
            A-=1
            L_ans[i]='C'
        else:
            A+=1
            C-=1
            L_ans[i]='A'
    elif S[i]=='BC':
        if C>B:
            B+=1
            C-=1
            L_ans[i]='B'
        elif C<B:
            C+=1
            B-=1
            L_ans[i]='C'
        elif B==C and S[i+1]=='AB':
            B+=1
            C-=1
            L_ans[i]='B'
        else:
            C+=1
            B-=1
            L_ans[i]='C'
    i+=1
    if any([A<0,B<0,C<0]):
        ans='No'
        break

print(ans)
if ans=='Yes':
    j=0
    while j<N:
        print(L_ans[j])
        j+=1