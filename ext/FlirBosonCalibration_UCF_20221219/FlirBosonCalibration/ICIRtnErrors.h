#pragma once
enum ErrorCode
{
	ici_error_unknown = -20 ,
	ici_error_null = -19 ,
	ici_error_null_file_pointer = -18 ,
	ici_error_empty_string = -17 ,
	ici_error_catch = -16 ,
	ici_error_already_exists = -15 ,
	ici_error_doesnt_exists = -14 ,
	ici_error_method_locked = -13 ,
	ici_error_device_not_found = -12 ,
	ici_error_device_already_in_use = -11 ,
	ici_error_not_little_endian_byte_order = -10 ,
	ici_error_non_radiometric_image = -9 ,
	ici_error_while_saving_ir_image = -8 ,
	ici_error_while_saving_visible_image = -7 ,
	ici_error_while_loading_ir_image = -6 ,
	ici_error_while_loading_visible_image = -5 ,
	ici_error_index_out_of_bound = -4 ,
	ici_jpeg_error_unidentified_header = -3 ,
	ici_jpeg_error_not_radiometric = -2 ,
	ici_error_none = 0 ,
};
