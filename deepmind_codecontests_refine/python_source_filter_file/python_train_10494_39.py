N,A,B,C,D = list(map(lambda x: int(x),input().split()))
S = " "+input()
def isAble():
    if "##" in S[A:C] or "##" in S[B:D]:
        return "No"
    if C>D:
        if "..." not in S[B-1:D+1]:
            return "No"
    return "Yes"

print(isAble())