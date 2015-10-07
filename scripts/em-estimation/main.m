%==================================================%
%=====Parameter optimization with EM-Algorithm=====%
%==================================================%
%=================Data Generation==================%
sigma_x = 0.01;       % Real data sigma
sigma_y_1 = 0.01;      % Metric data sigma
sigma_y_2 = 0.05;      % Visual data sigma
h_1 = 0.9;            % Metric data scale
h_2 = 2;              % Visual data scale
data = real_data(sigma_x, 20000);
metric_data = scaled_data(data, h_1, sigma_y_1);
visual_data = scaled_data(data, h_2, sigma_y_2);

%===============Parameter Proposal=================%
% h1: Scale of the visual measurements. It is
%     assumed in the range of 0 to 5
% h2: Scale of metric measurements. It is assumed as
%     gaussian centered in 1 but with sigma=0.1 due
%     to drift.
% sigma_x: Standard deviation of the real height
%     distribution.
% sigma_y: Standard deviation of measured height (sum
%     of metric and visual standard deviations)
h1 = unifrnd(0,5);
h2 = normrnd(1,0.1);
h = [h1 h2];
sigma_x = normrnd(0,0.2);
sigma_y = normrnd(0,0.2);
theta = [h sigma_x sigma_y];







%==================================================%
%==================Visualization===================%
%==================================================%
figure(1);
hold on;
plot(data, '-b')
plot(metric_data, '-r')
plot(visual_data, '-g')
legend('Real height data', 'Metric height data')
hold off;
