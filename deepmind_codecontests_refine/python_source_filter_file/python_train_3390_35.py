matrix = input()

r , c = matrix.split(" ")

count = 0

r_dict = []

while count < int(r):
    row = input()
    r_dict.append(row.split(" "))
    count +=1

flag = 0
for x in r_dict:
    if ("C" in x) or ("M" in x) or ("Y" in x):
        flag = 1
        break

if flag == 0:
    print ("#Black&White")
else:
    print ("#Colour")
    
    
                 
                        
    
            
        

        



            
        
            

        
            



        
        
    
        



            


    
    







    



        
        
        
        


            



        
            

    


    

    



        


        



    
        
        

    







    
    
 

    

        
    
            
    




    


        



    





        
            
        
    
