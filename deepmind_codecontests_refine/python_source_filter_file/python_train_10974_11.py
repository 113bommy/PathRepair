n = int (input ())
a = []
for i in range (n):
    var = []
    if i % 2 == 0:
        for i in range (n):
            if i % 2 == 0:
                var.append ("c")
            else:
                var.append (".")
    else:
        for i in range (n):
            if i % 2:
                var.append ("c")
            else:
                var.append(".")
    a.append (var)
print ((n ** 2 // 2)) if  n % 2 == 0 else print (((n ** 2) // 2) + 1)
for i in a:
    print ("".join (i))