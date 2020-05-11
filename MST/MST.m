a=importdata('Distance.txt');
Primf(a);

function [T,c] =Primf(a)
l=length(a);
a(a==0)=inf;
k=1:l;
listV(k)=0;
listV(1)=1;
e=1;
total_length=0;
while(e<l)
    min=inf;
    for i=1:l
        if listV(i)==1
            for j=1:l
                if listV(j)==0 & min>a(i,j)
                    min=a(i,j);
                    b=a(i,j);
                    s=i;
                    d=j;
                end
            end
        end
    end
  listV(d)=1;
    distance(e)=b;
    source(e)=s;
    destination(e)=d;
    e=e+1;
end
T=[source; destination];
for g=1:e-1
    c(g)=a(T(1,g),T(2,g));
    total_length=c(g)+total_length;
end
T
total_length
end