% Particle Filter implementation for scale estimation implementation
% with noisy measurements
% graphics_toolkit('gnuplot');

filename = '../data/data.csv';
data = csvread(filename);
filename = '../data/sample_pairs.csv';
samples = csvread(filename);

n_particles = 100;
particle_stddev = 1.0;

% Initialize particles
for i=1:n_particles
  particles(i) = normrnd(0, particle_stddev);
  weights(i) = 1/n_particles;
endfor

sz = size(samples)(1);
true_value = ones(1, sz, "uint8") * 2;

epsilon = 0.0000000000000001
for i=1:sz
  % Update weights
  for j=1:n_particles
    % x - y * lambda should be zero if scale is optimal
    error = (samples(i,2) - samples(i,3)*particles(j))^2;
    weights(j) = (1.0/(error + epsilon));
  endfor

  % Normalize weights
  s = sum(weights);
  weights = weights/s;

  % Get EAP
  eap = sum(particles.*weights);
  eaps(i) = eap;
  % Get MAP
  [val id] = max(weights);
  maps(i) = particles(id);

  % Resample particles
  for j=1:n_particles
    mu_prime = particles(j) + eap;
    particles(j) = normrnd(eap, particle_stddev);
  endfor

  waitbar(i/sz)
endfor

% max(particles)
% min(particles)
% max(eaps)
% min(eaps)

figure(1)
hold on
plot(samples(:,1), maps(:), '-b', 'linewidth', 2)
plot(samples(:,1), eaps(:), '-r', 'linewidth', 2)
plot(samples(:,1), true_value(:), '-g', 'linewidth', 2)
legend('EAP Estimator', 'MAP Estimator', 'True value')
hold off
