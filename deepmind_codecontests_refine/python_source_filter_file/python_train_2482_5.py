S,T=input(),input();l,m=len(S),len(T)
for i in range(l-m):
 if all(c in"?"+d for c,d in zip(S[-i-m:],T)):S=S.replace("?","a");print(S[:-i-m]+T+S[l-i:]);quit()
print("UNRESTORABLE")