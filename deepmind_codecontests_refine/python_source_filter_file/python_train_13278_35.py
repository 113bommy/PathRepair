#705A cf

def main():
    n= int(input())
    s="I Hate"
    for i in range(2,n+1):
        s+=" that I"
        if(i%2!=0):
            s+=" hate"
        else:
            s+=" love"
    s+=" it"
    print(s)
main()