a = 5
import base64
b = 7
# arthimatic operator 
print(a+b,a-b,a/b,a//b,a%b,a**b,a*b,sep="    ")
# bitwise operator
print(a&b,a or b , ~a,sep="     ")

print(a<<b,a>>b,sep="     ")
# ternary operator 
x = b if a > b else a
print(a)
# assignment opwrator 
# apllying function to the strign
a = "Dronacharya"
# accesign string 
print(a[3])
print(a[-3])
#traversing 
for i in a :
    print(i,end=",")
    #slicing 
    #[start:end:gap]
print(a[2:3])
#reverse 
print(a[::-1])
# 2 2 skip krke
print(a[::2])
# count() count the occurence of the given string 
print(a.count("a")) #3
#index return the index of the function
print(a.count("a")) #3
# find(0 the lowest index of the string)
print(a.find("a"))#4
#swaocase(0 swap the case to lowwer or vice versa) capitalise () upper() lower()
print(a.upper(),a.lower(),a.swapcase())
# encode 
x=a.encode()
print(a.encode())
print(x.decode())
y=base64.b64encode(a.encode())
print(y.decode())# b ht jayega decode likhne se

#apply casting to int using int() float using float() string using str()
mee=int(30)
mee2=str(30)
mee3=float(30)

#imput all the datatype and print the type

# print pyramid 

for i in range(5):
    for j in range(i):
     print("*")



