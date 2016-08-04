#ifndef single_surface_h
#define single_surface_h

#include <surfe_lib_module.h> // macro for importing / exporting dll

#include <modeling_methods.h>

class SURFE_LIB_EXPORT Single_Surface : public GRBF_Modelling_Methods {
private:
	bool _get_polynomial_matrix_block(MatrixXd &poly_matrix);
	bool _insert_polynomial_matrix_blocks_in_interpolation_matrix(const MatrixXd &poly_matrix, MatrixXd &interpolation_matrix);
public:
	// Constructor/Destructor
	Single_Surface(const model_parameters& m_p, const Basic_input& basic_i);
	~Single_Surface(){};
	// Methods
	Polynomial_Basis *create_polynomial_basis(const int &poly_order);
	bool get_interpolation_matrix(MatrixXd &interpolation_matrix);
	bool get_equality_values(VectorXd &equality_values);
	bool get_inequality_matrix(const MatrixXd &interpolation_matrix, MatrixXd &inequality_matrix);
	bool get_inequality_values(VectorXd &inequality_values);
	bool get_inequality_values(VectorXd &b,VectorXd &r);
	void eval_scalar_interpolant_at_point(Point &p);
	void eval_vector_interpolant_at_point(Point &p);
	bool get_method_parameters();
	bool process_input_data();
	bool setup_system_solver();
	bool get_minimial_and_excluded_input(Basic_input &greedy_input, Basic_input &excluded_input);
	bool measure_residuals(Basic_input &input);
	bool append_greedy_input(Basic_input &input);
	GRBF_Modelling_Methods *clone() { return new Single_Surface(*this); }
	// Attributes
	Polynomial_Basis *p_basis;
};

#endif
