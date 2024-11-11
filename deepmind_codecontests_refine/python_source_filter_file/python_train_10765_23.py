__author__ = 'david9517'

n=input()

def makeDigit(d):
    output=""
    if d<5:
        output+="-O|"
    elif d>=5:
        output+="O-|"
        d-=5
    for iter in range(0,5):
        if iter==d:
            output+="-"
        else:
            output+="O"
    return output

def makeSoroban(n):
    output=""
    if len(n)==0:
        return ""
    elif len(n)!=0:
        return makeSoroban(n[1:])+"\n" +makeDigit(int(n[0]))


   # for iter in range(0, len(n)):
       # output=makeDigit(int(n[iter]))+"\n"
  #  return output

print(makeSoroban(n))


