function data = real_data(sigma_x, n)
  alpha = 0.3;
  data=sin(alpha.*[0:0.001:20]);
  noise=normrnd(0,sigma_x,1,n+1);
  data=data.+noise;
endfunction
