def method(a,key):
    
    
    key_len = [ len(i) for i in key ]
    
    data = []
    
    for i in a:
        temp = None
        x,y,z = i[-key_len[0]::],i[-key_len[1]::],i[-key_len[2]::]
        
        if x in key:
            temp = key.index(x)
        elif y in key:
            temp = key.index(y)
        elif z in key:
            temp = key.index(z)
            
        if temp==None:
            return []
        else:
            data.append(temp)
            
    return data


def language(a):
    
    m =['lios','etr','initis']
    f =['liala','etra','inites']
    
    a = a.split()
    
    data_m = method(a,m)
    data_f = method(a,f)
    
    data = data_m if len(data_m)>len(data_f) else data_f
    
    try:
        assert len(a)==len(data)
        if len(data)==1:
            pass
        else:
            assert data.count(1)==1
        for i in range(len(data)-1):
            assert data[i]<=data[i+1]
        return "YES"
    except:
        return "NO"
        
        
a = input()
print(language(a))