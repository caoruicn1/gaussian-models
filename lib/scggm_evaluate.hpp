#include "scggm_theta.hpp"

#ifndef scggm_evaluate_HPP
#define scggm_evaluate_HPP

struct scggm_evaluate_obj {
  double value;
  int flag;
  scggm_theta grad;
};

scggm_evaluate_obj scggm_evaluate(scggm_theta theta, SMatrix Sx, SMatrix Sxy,
                                  SMatrix Sy, int N, char gradient,
                                  bool verbose) {
  scggm_evaluate_obj ret;
  ret.flag = 0;

  /*
  TODO
  [ cyy, p ]  = chol(theta.yy);

  if ( p > 0 )
        if strcmp(gradient, 'y') == 1 && verbose
                fprintf( 'sCGGM: Theta_yy not positive definite!\n' );
        end
        flag        = 1;
        value       = inf;
        grad        = theta;
        return;
  end

  logdetyy = 2 * sum(log(diag(cyy) ));

  if ( isnan(logdetyy) || isinf(logdetyy) )
        if verbose
                fprintf( 'sCGGM: logdet Theta_yy is Nan or Inf!\n' );
        end
        flag = 1;
        value = inf;
        grad = theta;
        return;
  end

  icyy	 = cyy \ eye(size(cyy,2));
  ithetayy = icyy * icyy';
  txyityy  = theta.xy*ithetayy;
  XtXth    = Sx*txyityy;
  txyXtXth = theta.xy'*Sx*txyityy;

  l1 = trace( theta.yy*Sy );
  l2 = trace( Sxy*theta.xy' );
  l3 = trace( txyXtXth );
  value = 0.5*l1 + l2 + 0.5*l3 - 0.5*N*logdetyy ;
  value = value / N;

  if strcmp('y',gradient) ==1
        grad.xy = (Sxy + XtXth)/N;
        grad.yy = 0.5*(Sy - N*ithetayy - ithetayy*txyXtXth)/N;
  else
        grad = [];
  end
  */

  return ret;
}

#endif
