import sys 
solSaved = {}
solSavedPropios = {}

def DivisorsN(n): 
    key = solSaved.get(str(n))
    if key == None : 
        divisors = []
        divisors2 = []
        for i in range(1,int(n ** (1/2)) + 1): 
            if n % i == 0 : 
                if abs(i - (n/i)) < 10 ** (-7) : divisors.append(int(i))
                else : 
                    divisors.append(int(i))
                    temp = []
                    temp.append(int(n/i))
                    divisors2 = temp + divisors2
        divisors = divisors + divisors2
        solSaved[str(n)] = divisors.copy()
        return divisors
    return key

def TodosLosDivisores(arrayN) : 
    sol = []
    if len(arrayN) > 10 ** 5 : 
        newArrayN = []
        for k in range(len(arrayN)): 
            newArrayN.append(arrayN[k])
        arrayN = newArrayN
    for i in range(len(arrayN) - 1):
        temp = DivisorsN(arrayN[i])
        for t in range(len(temp)) : sol.append(temp[t])
    #sol = sol + solSaved.get(str(arrayN[len(arrayN) - 1]))
    temp = sol.copy()
    temp2 = solSaved.get(str(arrayN[len(arrayN) - 1]))
    sol.append(temp2)
    for t in range(len(temp2)) : temp.append(temp2[t])
    solSaved[str(temp2)] = temp
    return sol

def DivisorsXk():
    a, b = input().split()
    x = int(a)
    k = int(b)
    if x == 1 : return 1
    if k == 0 : return x
    if k == 1 : return DivisorsN(x)
    sol = []
    sol.append(x)
    solSaved[str(x)] = DivisorsN(x)
    # index = 0
    # for i in range(k):
    #     prev_index = len(sol)
    #     for j in range(index, len(sol)):
    #         divs = DivisorsN(sol[j])
    #         sol = sol + divs
    #     index = prev_index
    i = 1
    while i <= k : 
        # j = 0
        # while j < len(sol): 
        #     if type(sol[j]) == int : newSol.append(DivisorsN(sol[j])) 
        #     else : newSol = newSol + DivisorAll(sol[j])
        #     j+=1
        # sol = newSol
        if type(sol[i - 1]) == int : sol.append(DivisorsN(sol[i - 1])) 
        else : sol.append(TodosLosDivisores(sol[i - 1]))
        i += 1
    temp = []
    temp2 = sol[len(sol) - 1]
    for t in range(len(temp2) - 1) : temp.append(temp2[t])
    temp = temp + temp2[len(temp2) - 1]
    return temp 

def LosFuckingDivisoresDeUnArrayConLista(a) : 
    sol = []
    if type(a) == int : return DivisorsN(a)
    for i in range(len(a)) : 
        temp = []
        key = solSaved.get(str(a[i]))
        if key == None : temp = LosFuckingDivisoresDeUnArrayConLista(a[i])
        else : temp = key
        sol.append(temp) 
    solSaved[str(a)] = sol
    return sol

def Divisors(x, k) : 
    if k == 0 : return x 
    if k > 10 ** 5 : 
        Ones = []
        for i in range(10 ** 5) : Ones.append(1)
        return Ones
    key = solSaved.get(str((x,k)))
    if key == None : 
        sol = []
        if type(x) == int : return Divisors(DivisorsN(x), k - 1)
        else : 
            sol = []
            for i in range(len(x)) : 
                temp = []
                temp.append(Divisors(x[i], k - 1))
                sol = sol + temp
            return sol
    else : return key

def DivisorsPropios(n) : 
    key = solSavedPropios.get(str(n))
    if key == None : 
        divisors = []
        divisors2 = []
        for i in range(2,int(n ** (1/2)) + 1): 
            if n % i == 0 : 
                if abs(i - (n/i)) < 10 ** (-7) : divisors.append(int(i))
                else : 
                    divisors.append(int(i))
                    temp = []
                    temp.append(int(n/i))
                    divisors2 = temp + divisors2 #divisors2.append(int(n / i))
        divisors = divisors + divisors2
        solSavedPropios[str(n)] = divisors.copy()
        return divisors
    return key

def UltimateDivisors(x, k) :
    if x == 1 : return 1
    if k == 0 : return x
    if k == 1 : return DivisorsN(x)
    if k >= 10 ** 5 : 
        a = []
        for i in range(10 ** 5) : a.append(1)
        return a
    Unos = []
    sol = []
    sol.append(1)
    temp = DivisorsPropios(x).copy()
    for i in range(k - 1) : Unos.append(1)
    if len(temp) == 0 : return [1] + Unos + [x]
    temp.append(x)
    for t in range(len(temp)) : 
        if len(sol) >= 10 ** 5 : return sol
        temp3 = DivisorsPropios(temp[t]).copy()
        if len(temp3) == 0 : 
            temp4 = UltimateDivisors(temp[t], k - 1)
            if type(temp4) == int : sol = sol  + [temp4]
            else : sol = sol + temp4
        else : sol = sol + NewUltimateDivisores(temp[t], k - 1)
    return sol

def NewUltimateDivisores(x, k) : 
    temp = DivisorsPropios(x)
    i = k - 1
    sol = []
    while i >= 1 : 
        if len(sol) >= 10**5 : return sol
        sol = sol + [1]
        for t in range(len(temp)) : 
            temp2 = UltimateDivisors(temp[t], i)
            if type(temp2) == int : sol = sol + [temp2]
            else : sol = sol + temp2
        i -= 1
    return sol + DivisorsN(x)

#print(UltimateDivisors(963761198400,65535))
#print(UltimateDivisors(549755813888,269))

a, b = input().split()
x = int(a)
k = int(b)
sol = UltimateDivisors(x,k)
if type(sol) == int : print(sol)
else :     
    if(len(sol) >= 10 ** 5):
        for i in range(10 ** 5 - 1) : 
            sys.stdout.write(str(sol[i]) + ' ')
        sys.stdout.write(str(sol[10**5 - 1]))
    else :  
        for i in range(len(sol) - 1) : 
            sys.stdout.write(str(sol[i]) + ' ')
        sys.stdout.write(str(sol[len(sol) - 1]))
