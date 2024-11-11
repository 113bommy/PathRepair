m = {1:"January", 2:"February", 3:"March", 4:"April", 5:"May", 6:"June", 7:"July", 8:"August", 9:"September", 10:"October",11 :"November", 12:"December"}
im = {v: k for k, v in m.items()}
n = input("")
l = int(input(""))
if (im[n] + l) % 12 != 0:
    print(m[(im[n] + l) % 12])
else:
    print(n)