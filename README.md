Vehicle Manager (Qt/C++)



A Qt-based desktop application for managing vehicles with a class hierarchy of Vehicle → Car/Jeep/SUV/Truck.

Supports adding, editing, deleting, and saving vehicle data in JSON/CSV formats.

Built using Qt 6 and modern C++17.



✨ Features



🚗 Class hierarchy with inheritance:



Vehicle (base class)



Car, Jeep, SUV, Truck (derived classes)



🖥️ Qt GUI for managing vehicle list (add, edit, delete)



💾 Save/load vehicle data to/from JSON and CSV files



🎨 Styled UI with icons for different vehicle types



⚙️ Modular backend logic separated from UI for easy extension



🛠️ Requirements



Qt 6.x (tested with Qt 6.9)



CMake 3.16+



A C++17 compatible compiler (GCC, Clang, or MSVC)



🚀 Build Instructions

Clone repository



git clone https://github.com/babarcha/VehicleManager.git

cd VehicleManager

Create build directory

mkdir build && cd build

Configure with CMake

cmake .. -DCMAKE_BUILD_TYPE=Release

Build project

cmake --build . --config Release -j

▶️ Run

After building, run the executable:

Linux/macOS:
./build/bin/VehicleManager

Windows:
.\build\Release\VehicleManager.exe

Usage

Launch the app.

Add new vehicles by selecting type (Car, Jeep, SUV, Truck).

Edit or delete existing entries.

Save the current list to JSON or CSV.

Load saved vehicle data back into the app.

📸 Screenshots

(Add PNGs inside /docs or /assets and link them here)


Main GUI showing the vehicle list.


Dialog for adding a new vehicle.

📌 Future Improvements

🔄 Sorting and filtering options (e.g., by type, model, year)

📝 Import/export in XML format

🖼️ Improved styling with custom icons and themes

📊 Statistics view (e.g., number of each vehicle type)

🌐 Cloud sync option for vehicle data

📄 License

MIT License – feel free to use and modify.