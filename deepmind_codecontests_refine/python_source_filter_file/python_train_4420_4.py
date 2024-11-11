#40.443A Anton and letters
l = input()
a = []
for i in l:
    if i in "abcdefghijklmopqrstuvwxyz" and i not in a:
        a.append(i)
print(len(a))