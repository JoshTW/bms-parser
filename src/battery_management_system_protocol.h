#ifndef BATTERY_MANAGEMENT_SYSTEM_PROTOCOL_H_
#define BATTERY_MANAGEMENT_SYSTEM_PROTOCOL_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

/**
 * Many modern general purpose BMS include a UART/Bluetooth based communication interface.
 * After sending read requests they respond with various information's about the battery state in
 * a custom binary format.
 * \sa https://www.lithiumbatterypcb.com/Protocol%20English%20Version.rar Source
 */

class battery_management_system_protocol_t : public kaitai::kstruct {

public:
    class cell_voltages_t;
    class read_req_t;
    class hardware_t;
    class response_t;
    class basic_info_t;
    class write_req_t;

    enum commands_t {
        COMMANDS_WRITE = 90,
        COMMANDS_READ = 165
    };

    enum registers_t {
        REGISTERS_BASIC_INFO = 3,
        REGISTERS_CELL_VOLTAGES = 4,
        REGISTERS_HARDWARE = 5
    };

    battery_management_system_protocol_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, battery_management_system_protocol_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~battery_management_system_protocol_t();

    class cell_voltages_t : public kaitai::kstruct {

    public:
        class voltage_t;

        cell_voltages_t(kaitai::kstream* p__io, battery_management_system_protocol_t::response_t* p__parent = 0, battery_management_system_protocol_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~cell_voltages_t();

        class voltage_t : public kaitai::kstruct {

        public:

            voltage_t(kaitai::kstream* p__io, battery_management_system_protocol_t::cell_voltages_t* p__parent = 0, battery_management_system_protocol_t* p__root = 0);

        private:
            void _read();
            void _clean_up();

        public:
            ~voltage_t();

        private:
            bool f_volt;
            double m_volt;

        public:

            /**
             * Cell voltage (V)
             */
            double volt();

        private:
            uint16_t m_raw;
            battery_management_system_protocol_t* m__root;
            battery_management_system_protocol_t::cell_voltages_t* m__parent;

        public:

            /**
             * Cell voltage (raw)
             */
            uint16_t raw() const { return m_raw; }
            battery_management_system_protocol_t* _root() const { return m__root; }
            battery_management_system_protocol_t::cell_voltages_t* _parent() const { return m__parent; }
        };

    private:
        std::vector<voltage_t*>* m_cells;
        battery_management_system_protocol_t* m__root;
        battery_management_system_protocol_t::response_t* m__parent;

    public:
        std::vector<voltage_t*>* cells() const { return m_cells; }
        battery_management_system_protocol_t* _root() const { return m__root; }
        battery_management_system_protocol_t::response_t* _parent() const { return m__parent; }
    };

    class read_req_t : public kaitai::kstruct {

    public:

        read_req_t(kaitai::kstream* p__io, battery_management_system_protocol_t* p__parent = 0, battery_management_system_protocol_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~read_req_t();

    private:
        uint8_t m_req_cmd;
        std::string m_len_data;
        battery_management_system_protocol_t* m__root;
        battery_management_system_protocol_t* m__parent;

    public:

        /**
         * Same value as cmd for response
         */
        uint8_t req_cmd() const { return m_req_cmd; }
        std::string len_data() const { return m_len_data; }
        battery_management_system_protocol_t* _root() const { return m__root; }
        battery_management_system_protocol_t* _parent() const { return m__parent; }
    };

    class hardware_t : public kaitai::kstruct {

    public:

        hardware_t(kaitai::kstream* p__io, battery_management_system_protocol_t::response_t* p__parent = 0, battery_management_system_protocol_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~hardware_t();

    private:
        std::string m_version;
        battery_management_system_protocol_t* m__root;
        battery_management_system_protocol_t::response_t* m__parent;

    public:

        /**
         * BMS model and version specification
         */
        std::string version() const { return m_version; }
        battery_management_system_protocol_t* _root() const { return m__root; }
        battery_management_system_protocol_t::response_t* _parent() const { return m__parent; }
    };

    class response_t : public kaitai::kstruct {

    public:

        enum status_t {
            STATUS_OK = 0,
            STATUS_FAIL = 128
        };

        response_t(uint8_t p_cmd, kaitai::kstream* p__io, battery_management_system_protocol_t* p__parent = 0, battery_management_system_protocol_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~response_t();

    private:
        status_t m_status;
        uint8_t m_len_data;
        kaitai::kstruct* m_data;
        bool n_data;

    public:
        bool _is_null_data() { data(); return n_data; };

    private:
        uint8_t m_cmd;
        battery_management_system_protocol_t* m__root;
        battery_management_system_protocol_t* m__parent;
        std::string m__raw_data;
        kaitai::kstream* m__io__raw_data;

    public:
        status_t status() const { return m_status; }
        uint8_t len_data() const { return m_len_data; }
        kaitai::kstruct* data() const { return m_data; }
        uint8_t cmd() const { return m_cmd; }
        battery_management_system_protocol_t* _root() const { return m__root; }
        battery_management_system_protocol_t* _parent() const { return m__parent; }
        std::string _raw_data() const { return m__raw_data; }
        kaitai::kstream* _io__raw_data() const { return m__io__raw_data; }
    };

    class basic_info_t : public kaitai::kstruct {

    public:
        class fet_bits_t;
        class prot_list_t;
        class date_t;
        class temp_t;
        class current_t;
        class voltage_t;
        class balance_list_t;
        class capacity_t;

        basic_info_t(kaitai::kstream* p__io, battery_management_system_protocol_t::response_t* p__parent = 0, battery_management_system_protocol_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~basic_info_t();

        class fet_bits_t : public kaitai::kstruct {

        public:

            fet_bits_t(kaitai::kstream* p__io, battery_management_system_protocol_t::basic_info_t* p__parent = 0, battery_management_system_protocol_t* p__root = 0);

        private:
            void _read();
            void _clean_up();

        public:
            ~fet_bits_t();

        private:
            uint64_t m_reserved;
            bool m_is_discharge_enabled;
            bool m_is_charge_enabled;
            battery_management_system_protocol_t* m__root;
            battery_management_system_protocol_t::basic_info_t* m__parent;

        public:
            uint64_t reserved() const { return m_reserved; }
            bool is_discharge_enabled() const { return m_is_discharge_enabled; }
            bool is_charge_enabled() const { return m_is_charge_enabled; }
            battery_management_system_protocol_t* _root() const { return m__root; }
            battery_management_system_protocol_t::basic_info_t* _parent() const { return m__parent; }
        };

        class prot_list_t : public kaitai::kstruct {

        public:

            prot_list_t(kaitai::kstream* p__io, battery_management_system_protocol_t::basic_info_t* p__parent = 0, battery_management_system_protocol_t* p__root = 0);

        private:
            void _read();
            void _clean_up();

        public:
            ~prot_list_t();

        private:
            uint64_t m_reserved;
            bool m_is_fet_lock;
            bool m_is_ic_error;
            bool m_is_ocp_short;
            bool m_is_ocp_discharge;
            bool m_is_ocp_charge;
            bool m_is_utp_discharge;
            bool m_is_otp_discharge;
            bool m_is_utp_charge;
            bool m_is_otp_charge;
            bool m_is_uvp_pack;
            bool m_is_ovp_pack;
            bool m_is_uvp_cell;
            bool m_is_ovp_cell;
            battery_management_system_protocol_t* m__root;
            battery_management_system_protocol_t::basic_info_t* m__parent;

        public:
            uint64_t reserved() const { return m_reserved; }
            bool is_fet_lock() const { return m_is_fet_lock; }
            bool is_ic_error() const { return m_is_ic_error; }
            bool is_ocp_short() const { return m_is_ocp_short; }
            bool is_ocp_discharge() const { return m_is_ocp_discharge; }
            bool is_ocp_charge() const { return m_is_ocp_charge; }
            bool is_utp_discharge() const { return m_is_utp_discharge; }
            bool is_otp_discharge() const { return m_is_otp_discharge; }
            bool is_utp_charge() const { return m_is_utp_charge; }
            bool is_otp_charge() const { return m_is_otp_charge; }
            bool is_uvp_pack() const { return m_is_uvp_pack; }
            bool is_ovp_pack() const { return m_is_ovp_pack; }
            bool is_uvp_cell() const { return m_is_uvp_cell; }
            bool is_ovp_cell() const { return m_is_ovp_cell; }
            battery_management_system_protocol_t* _root() const { return m__root; }
            battery_management_system_protocol_t::basic_info_t* _parent() const { return m__parent; }
        };

        class date_t : public kaitai::kstruct {

        public:

            date_t(kaitai::kstream* p__io, battery_management_system_protocol_t::basic_info_t* p__parent = 0, battery_management_system_protocol_t* p__root = 0);

        private:
            void _read();
            void _clean_up();

        public:
            ~date_t();

        private:
            bool f_year;
            int32_t m_year;

        public:

            /**
             * only years from 2000 to 2127 (2000 + 127) can be represented
             */
            int32_t year();

        private:
            uint64_t m_year_after_2000;
            uint64_t m_month;
            uint64_t m_day;
            battery_management_system_protocol_t* m__root;
            battery_management_system_protocol_t::basic_info_t* m__parent;

        public:
            uint64_t year_after_2000() const { return m_year_after_2000; }
            uint64_t month() const { return m_month; }
            uint64_t day() const { return m_day; }
            battery_management_system_protocol_t* _root() const { return m__root; }
            battery_management_system_protocol_t::basic_info_t* _parent() const { return m__parent; }
        };

        class temp_t : public kaitai::kstruct {

        public:

            temp_t(kaitai::kstream* p__io, battery_management_system_protocol_t::basic_info_t* p__parent = 0, battery_management_system_protocol_t* p__root = 0);

        private:
            void _read();
            void _clean_up();

        public:
            ~temp_t();

        private:
            bool f_celsius;
            double m_celsius;

        public:
            double celsius();

        private:
            uint16_t m_raw;
            battery_management_system_protocol_t* m__root;
            battery_management_system_protocol_t::basic_info_t* m__parent;

        public:
            uint16_t raw() const { return m_raw; }
            battery_management_system_protocol_t* _root() const { return m__root; }
            battery_management_system_protocol_t::basic_info_t* _parent() const { return m__parent; }
        };

        class current_t : public kaitai::kstruct {

        public:

            current_t(kaitai::kstream* p__io, battery_management_system_protocol_t::basic_info_t* p__parent = 0, battery_management_system_protocol_t* p__root = 0);

        private:
            void _read();
            void _clean_up();

        public:
            ~current_t();

        private:
            bool f_amp;
            double m_amp;

        public:

            /**
             * Actual current (A)
             */
            double amp();

        private:
            int16_t m_raw;
            battery_management_system_protocol_t* m__root;
            battery_management_system_protocol_t::basic_info_t* m__parent;

        public:

            /**
             * Actual current (raw)
             */
            int16_t raw() const { return m_raw; }
            battery_management_system_protocol_t* _root() const { return m__root; }
            battery_management_system_protocol_t::basic_info_t* _parent() const { return m__parent; }
        };

        class voltage_t : public kaitai::kstruct {

        public:

            voltage_t(kaitai::kstream* p__io, battery_management_system_protocol_t::basic_info_t* p__parent = 0, battery_management_system_protocol_t* p__root = 0);

        private:
            void _read();
            void _clean_up();

        public:
            ~voltage_t();

        private:
            bool f_volt;
            double m_volt;

        public:

            /**
             * Pack voltage (V)
             */
            double volt();

        private:
            uint16_t m_raw;
            battery_management_system_protocol_t* m__root;
            battery_management_system_protocol_t::basic_info_t* m__parent;

        public:

            /**
             * Pack voltage (raw)
             */
            uint16_t raw() const { return m_raw; }
            battery_management_system_protocol_t* _root() const { return m__root; }
            battery_management_system_protocol_t::basic_info_t* _parent() const { return m__parent; }
        };

        class balance_list_t : public kaitai::kstruct {

        public:

            balance_list_t(kaitai::kstream* p__io, battery_management_system_protocol_t::basic_info_t* p__parent = 0, battery_management_system_protocol_t* p__root = 0);

        private:
            void _read();
            void _clean_up();

        public:
            ~balance_list_t();

        private:
            std::vector<bool>* m_is_balancing;
            battery_management_system_protocol_t* m__root;
            battery_management_system_protocol_t::basic_info_t* m__parent;

        public:
            std::vector<bool>* is_balancing() const { return m_is_balancing; }
            battery_management_system_protocol_t* _root() const { return m__root; }
            battery_management_system_protocol_t::basic_info_t* _parent() const { return m__parent; }
        };

        class capacity_t : public kaitai::kstruct {

        public:

            capacity_t(kaitai::kstream* p__io, battery_management_system_protocol_t::basic_info_t* p__parent = 0, battery_management_system_protocol_t* p__root = 0);

        private:
            void _read();
            void _clean_up();

        public:
            ~capacity_t();

        private:
            bool f_amp_hour;
            double m_amp_hour;

        public:

            /**
             * Capacity (Ah)
             */
            double amp_hour();

        private:
            uint16_t m_raw;
            battery_management_system_protocol_t* m__root;
            battery_management_system_protocol_t::basic_info_t* m__parent;

        public:

            /**
             * Capacity (raw)
             */
            uint16_t raw() const { return m_raw; }
            battery_management_system_protocol_t* _root() const { return m__root; }
            battery_management_system_protocol_t::basic_info_t* _parent() const { return m__parent; }
        };

    private:
        voltage_t* m_pack_voltage;
        current_t* m_pack_current;
        capacity_t* m_remain_cap;
        capacity_t* m_typ_cap;
        uint16_t m_cycles;
        date_t* m_prod_date;
        balance_list_t* m_balance_status;
        prot_list_t* m_prot_status;
        uint8_t m_software_version;
        uint8_t m_remain_cap_percent;
        fet_bits_t* m_fet_status;
        uint8_t m_cell_count;
        uint8_t m_num_temps;
        std::vector<temp_t*>* m_temps;
        battery_management_system_protocol_t* m__root;
        battery_management_system_protocol_t::response_t* m__parent;
        std::vector<std::string>* m__raw_temps;
        std::vector<kaitai::kstream*>* m__io__raw_temps;

    public:
        voltage_t* pack_voltage() const { return m_pack_voltage; }
        current_t* pack_current() const { return m_pack_current; }
        capacity_t* remain_cap() const { return m_remain_cap; }
        capacity_t* typ_cap() const { return m_typ_cap; }

        /**
         * Cycle times
         */
        uint16_t cycles() const { return m_cycles; }

        /**
         * Production date
         */
        date_t* prod_date() const { return m_prod_date; }

        /**
         * List of balance bits
         */
        balance_list_t* balance_status() const { return m_balance_status; }

        /**
         * List of protection bits
         */
        prot_list_t* prot_status() const { return m_prot_status; }
        uint8_t software_version() const { return m_software_version; }

        /**
         * Portion of remaining capacity
         */
        uint8_t remain_cap_percent() const { return m_remain_cap_percent; }
        fet_bits_t* fet_status() const { return m_fet_status; }
        uint8_t cell_count() const { return m_cell_count; }
        uint8_t num_temps() const { return m_num_temps; }
        std::vector<temp_t*>* temps() const { return m_temps; }
        battery_management_system_protocol_t* _root() const { return m__root; }
        battery_management_system_protocol_t::response_t* _parent() const { return m__parent; }
        std::vector<std::string>* _raw_temps() const { return m__raw_temps; }
        std::vector<kaitai::kstream*>* _io__raw_temps() const { return m__io__raw_temps; }
    };

    class write_req_t : public kaitai::kstruct {

    public:

        write_req_t(kaitai::kstream* p__io, battery_management_system_protocol_t* p__parent = 0, battery_management_system_protocol_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~write_req_t();

    private:
        uint8_t m_req_cmd;
        uint8_t m_len_write_data;
        std::string m_write_data;
        battery_management_system_protocol_t* m__root;
        battery_management_system_protocol_t* m__parent;

    public:

        /**
         * Same value as cmd for response
         */
        uint8_t req_cmd() const { return m_req_cmd; }
        uint8_t len_write_data() const { return m_len_write_data; }
        std::string write_data() const { return m_write_data; }
        battery_management_system_protocol_t* _root() const { return m__root; }
        battery_management_system_protocol_t* _parent() const { return m__parent; }
    };

private:
    bool f_ofs_body_start;
    int32_t m_ofs_body_start;

public:
    int32_t ofs_body_start();

private:
    bool f_ofs_body_end;
    int32_t m_ofs_body_end;

public:
    int32_t ofs_body_end();

private:
    bool f_checksum_input;
    std::string m_checksum_input;

public:
    std::string checksum_input();

private:
    std::string m_magic_start;
    uint8_t m_cmd;
    std::string m__unnamed2;
    bool n__unnamed2;

public:
    bool _is_null__unnamed2() { _unnamed2(); return n__unnamed2; };

private:
    kaitai::kstruct* m_body;
    std::string m__unnamed4;
    bool n__unnamed4;

public:
    bool _is_null__unnamed4() { _unnamed4(); return n__unnamed4; };

private:
    uint16_t m_checksum;
    std::string m_magic_end;
    battery_management_system_protocol_t* m__root;
    kaitai::kstruct* m__parent;

public:
    std::string magic_start() const { return m_magic_start; }
    uint8_t cmd() const { return m_cmd; }
    std::string _unnamed2() const { return m__unnamed2; }
    kaitai::kstruct* body() const { return m_body; }
    std::string _unnamed4() const { return m__unnamed4; }

    /**
     * Should be equal to the result from: 0x10000 - sum(body)
     * Where sum() is calculated over the value of every byte individually. This works
     * for up to 256 bytes, for more it must be clamped to 16 bits: result & 0xffff
     * Body includes everything besides magic start/end byte, cmd and checksum,
     * so excluding 2 bytes at the beginning and 3 bytes at the end.
     */
    uint16_t checksum() const { return m_checksum; }
    std::string magic_end() const { return m_magic_end; }
    battery_management_system_protocol_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // BATTERY_MANAGEMENT_SYSTEM_PROTOCOL_H_
