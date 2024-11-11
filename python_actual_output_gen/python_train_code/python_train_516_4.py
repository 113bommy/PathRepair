n=input()+'b'
print(('YES','NO')[all(x in 'aeioun' or y in 'aeiou' for x,y in zip(n,n[1:]))])