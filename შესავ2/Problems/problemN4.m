%%ამოცანა 4;
%%a.
aVec = [3.14,15,9,26];
bVec = [2.71;8;28;128];
cVec = [-5:0.2:5];
dVec = logspace(0,1,101);
eVec = 'Hello';
aMat = ones(9) * 2;
xMat = (aVec*bVec)*aMat^2;
%% b.
yMat = (bVec*aVec);
%%c.
A = 1:100;
cMat = reshape(A, [10,10]);
vec = [1, 2, 3, 4, 5, 4, 3, 2, 1];
bMat = diag(vec, 0);
zMat = det(cMat)*transpose((aMat*bMat));