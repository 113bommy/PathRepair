def main():
    out = ""
    
    fixes = {'0':2,'1':6,'2':2,'3':3,'4':3,'5':4,'6':2,'7':5,'8':1,'9':2}
    n = input()
    
    return fixes[n[0]]*fixes[n[1]]

if __name__ == '__main__':
    print(main())   