# def pow(a,b):
#     ans=1
#     while b:
#         if(b%2):
#             ans=ans*a
#         a=a*a
#         b=b>>1
#     return ans
n=int(input())
if(n-4>=0):
    print(2*3*4*4**(n-3)+(n-3)*4*3*3*4*(n-4))
else:
    print(2*3*4*4**(n-3))