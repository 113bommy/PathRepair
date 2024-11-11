h,w=map(int,input().split())
x=[]
for i in range(1,w):
    x1=[h*i,h*((w-i)//2),h*(w-i)-h*((w-i)//2)]
    x2=[h*i,(w-i)*(h//2),h*(w-i)-(w-i)*(h//2)]
    x.append(min(max(x1)-min(x1),max(x2)-min(x2))
for i in range(1,h):
    x1=[w*i,w*((h-i)//2),w*(h-i)-w*((h-i)//2)]
    x2=[w*i,(h-i)*(w//2),w*(h-i)-(h-i)*(w//2)]
    x.append(min(max(x1)-min(x1),max(x2)-min(x2))
print(min(x))
