n = int(input())
for case in range(n):
    word = input()
    if word[--1:] =='o':
        print("FILIPINO")
    elif word[-1:] =='u':
        print("JAPANESE")
    else:
        print("KOREAN")
        
        
