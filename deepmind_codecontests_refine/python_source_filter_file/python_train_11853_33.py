h,w = map(int,input().split())
a = [input() for i in range(h)]
print(a)
print('#'*(w+2))
for i in a:
    print('#'+i+'#')
print('#'*(w+2))