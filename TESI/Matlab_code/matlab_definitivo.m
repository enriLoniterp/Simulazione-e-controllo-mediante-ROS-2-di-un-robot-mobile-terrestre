A=load('3-3k=3.txt');
B=load('3-3k=5.txt');
C=load('3-3k=10.txt');
w=0.5;
h=0.5;
x0=-w/2;
y0=-h/2;

angolo =A(:,1);
x=A(:,2);
y=A(:,3);
angoloy =B(:,1);
xb=B(:,2);
yb=B(:,3);
angoloz =C(:,1);
xc=B(:,2);
yc=B(:,3);

theta=angolo(1);
Rz=[cos(theta) -sin(theta); sin(theta) cos(theta)];
xv=[x0 x0+w x0+w x0 x0];yv=[y0 y0 y0+h y0+h y0];
P(1,:)=xv;P(2,:)=yv;
XY=Rz*P;
xadd=[0.0 0.0 0.0 0.0 0.0];
yadd=[0.0 0.0 0.0 0.0 0.0];
ADD=[xadd;yadd];
XY_new=XY+ADD;
plot(XY_new(1,:),XY_new(2,:),'r','MarkerFaceColor','red');
grid on;
axis([-10 10 -10 10]);

hold on
theta = angolo(end);
Rz=[cos(theta) -sin(theta);sin(theta) cos(theta)];
xv=[x0 x0+w x0+w x0 x0];yv=[y0 y0 y0+h y0+h y0];
P(1,:)=xv;P(2,:)=yv;
XY=Rz*P;
xadd=[x(end) x(end) x(end) x(end) x(end)];
yadd=[y(end) y(end) y(end) y(end) y(end)];
ADD=[xadd;yadd];
XY_new=XY+ADD;
xlabel('x')
ylabel('y')
plot(XY_new(1,:),XY_new(2,:),'r','MarkerFaceColor','blue');
grid on;
axis([-10 10 -10 10]);
plot(A(1:end,2),A(1:end,3),'red');
plot(B(1:end,2),B(1:end,3),'r');
plot(C(1:end,2),C(1:end,3),'red');
