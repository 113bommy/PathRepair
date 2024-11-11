#coding:UTF-8

def RoT(A,B,ans):
    if A:
        root=A[0]
        rindex=B.index(root)
        Aleft=A[1:rindex+1]
        Aright=A[rindex+1:]
        Bleft=B[:rindex]
        Bright=B[rindex:]
        RoT(Aleft,Bleft,ans)
        RoT(Aright,Bright,ans)
        ans.append(root)
        
        


if __name__=="__main__":
    n=int(input())
    A=input().split(" ")
    B=input().split(" ")
    ans=[]
    RoT(A,B,ans)
    print(" ".join(ans))